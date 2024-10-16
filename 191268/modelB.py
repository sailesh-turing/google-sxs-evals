import os
import aiofiles
from fastapi import UploadFile

# ... other imports and class definition ...
TEMP_DIR = ""
async def insert_documents(self, file: UploadFile, isScraped: bool):
    try:
        file_location = os.path.join(TEMP_DIR, file.filename)

        async with aiofiles.open(file_location, 'wb') as out_file:
            async for chunk in file.chunks():  # Use file.chunks for better memory management
                await out_file.write(chunk)

        async with self.pinecone_client() as client:
            # Await the upsert operation! This is crucial.
            await client.upsert_embeddings(file_location, isScraped)

    finally:  # Ensure cleanup even if errors occur
        if os.path.exists(file_location):
            os.remove(file_location)


# Example pinecone_client context manager (adapt to your actual implementation)
async def pinecone_client(self):
    # ... your code to initialize the Pinecone client ...
    try:
        yield client  # Yield the client for use within the 'async with' block
    finally:
        # ... your code to close the Pinecone client connection ...
        pass

