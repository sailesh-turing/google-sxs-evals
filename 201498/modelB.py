import shutil
import os
import re

def process_pdfs(source_dir, dest_dir):
    for filename in os.listdir(source_dir):
        if filename.endswith(".pdf"):
            source_path = os.path.join(source_dir, filename)
            # Example renaming logic (replace with your specific needs)
            new_filename = re.sub(r'[^a-zA-Z0-9]', '_', filename) 
            dest_path = os.path.join(dest_dir, new_filename)
            shutil.copy2(source_path, dest_path)

# Example usage
source_directory = "./source"
destination_directory = "./destination"
process_pdfs(source_directory, destination_directory) 