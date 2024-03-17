from rest_framework.test import APIRequestFactory
from django.test import TestCase


class MyTest(TestCase):
    def test_my_test(self):
        factory = APIRequestFactory()
        request = factory.get("/api/hello")
        print(request)
        self.assertEquals(request, "{\"message\":\"Hello World\"}")