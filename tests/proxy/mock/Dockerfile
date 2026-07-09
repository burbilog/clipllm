FROM python:3.12-alpine
WORKDIR /app
COPY mock.py /app/mock.py
EXPOSE 8080
# Plain HTTP, no SSL -- this is a test fixture on an isolated network.
CMD ["python3", "/app/mock.py"]
