FROM python:3.12

WORKDIR /app

COPY requirements.txt .

RUN pip install -r requirements.txt

COPY ./app/ .

EXPOSE 8000

CMD [ "daphne", "app.asgi:application", "-b", "0.0.0.0"]