FROM python:3.12

WORKDIR /app

COPY . .

# Install dependencies:
COPY requirements.txt .
RUN pip install -r requirements.txt

EXPOSE 8000

CMD [\
    "/bin/bash", "-c",\
    "\
    python manage.py makemigrations chat && \
    python manage.py migrate chat &&\
    daphne websocket.asgi:application -b 0.0.0.0\
    "\
]
