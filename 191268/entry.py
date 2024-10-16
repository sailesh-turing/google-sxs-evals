from fastapi import UploadFile
import asyncio
import modelB as modelResponse

def main():
    file_name = "sample.png"
    file_content = open(file_name, "rb").read()
    # headers = {
    #             'content-type': mime_type
    #           }
    upload_file = UploadFile(file=file_content, filename=file_name)
    asyncio.run(modelResponse.insert_documents(modelResponse, upload_file, False))

main()
