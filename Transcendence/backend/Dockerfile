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
    python manage.py makemigrations api && \
    python manage.py migrate api &&\
    daphne trascendence.asgi:application -b 0.0.0.0\
    "\
]
