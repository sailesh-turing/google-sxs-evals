import os
import shutil

def process_pdfs(source_dir, dest_dir):
    for filename in os.listdir(source_dir):
        if filename.endswith(".pdf"):
            source_path = os.path.join(source_dir, filename)
            dest_path = os.path.join(dest_dir, filename.replace("old", "new"))  # Example renaming
            shutil.copy2(source_path, dest_path)

if __name__ == "__main__":
    source_directory = "./source"
    destination_directory = "./destination"
    process_pdfs(source_directory, destination_directory)