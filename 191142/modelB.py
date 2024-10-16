import base64
from google.cloud import vision

# Replace with your Google Cloud project ID
project_id = "YOUR_PROJECT_ID"

def encode_image(image_path):
    with open(image_path, "rb") as image_file:
        return base64.b64encode(image_file.read()).decode('utf-8')

def detect_text(base64_image):
    client = vision.ImageAnnotatorClient()
    image = vision.Image(content=base64.b64decode(base64_image))
    response = client.text_detection(image=image)
    texts = response.text_annotations
    if texts:
        return texts[0].description  # Return the detected text
    return ""


def generate_image_caption(text):
    #  This part needs to be implemented using a suitable Google AI image captioning model.
    #  Currently, there's no direct equivalent to OpenAI's chat completion for image captioning in the Vertex AI Python client library.
    #  You'll need to use a model like the Vision API's image captioning feature or a custom-trained model deployed on Vertex AI.

    # Placeholder using Vision API's label detection (not ideal for captions but demonstrates API usage)
    client = vision.ImageAnnotatorClient()
    image = vision.Image(content=base64.b64decode(base64_image)) # Reusing the image
    response = client.label_detection(image=image)
    labels = response.label_annotations
    caption = " ".join([label.description for label in labels])
    return caption



# Path to your image
image_path = "test.png"

# Getting the base64 string
base64_image = encode_image(image_path)

# Detect text in the image (if any)
detected_text = detect_text(base64_image)

# Generate a caption (or process the image as needed)
#  Replace the placeholder with actual image captioning logic
caption = generate_image_caption(detected_text)


print(f"Detected Text: {detected_text}")
print(f"Generated Caption/Response: {caption}")



# Example of how to call the Vision API's image captioning feature (if available in your region):
#  (This is commented out because it's not consistently available and requires specific setup)
"""
try:
    response = client.image_properties(image=image) # client is the Vision API client
    properties = response.image_properties_annotation
    if properties.dominant_colors: # Example: Accessing dominant colors
        print("Dominant colors:")
        for color in properties.dominant_colors.colors:
            print(f"  - {color.color}")
except Exception as e:
    print(f"Error using image properties: {e}")
"""