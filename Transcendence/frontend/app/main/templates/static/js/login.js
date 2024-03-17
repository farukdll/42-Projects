(function () {
  takeUrl();
  document.querySelector("#form-sign-in").addEventListener('submit', (e) => {
    e.preventDefault()
    signInUser()
  })
  document.querySelector('#form-register').addEventListener('submit', (e) => {
    e.preventDefault()
    registerUser()
  })
})()

function control_password(name) {
  let in_pass = document.getElementById("register-password");
  let get = document.getElementById(name);
  if (name == "register-password-too") {
    document.getElementById("input-password-too").style.display = "block";
    if (in_pass.value == get.value) {
      document.getElementById("register-submit").style.pointerEvents = "auto";
      document.getElementById("input-password-too").style.color = "green";
    }
    else
      document.getElementById("input-password-too").style.color = "red";
  }
  else {
    document.getElementById("input-password").style.display = "block";
    if (get.value.lenght() > 6)
      document.getElementById("input-password").style.color = "green";
    else
      document.getElementById("input-password").style.color = "yellow";
  }
}

async function takeUrl() {
  let url = "http://localhost/api/auth/sign-in/42"
  let myUrl = window.location.search;
  let searchParams = new URLSearchParams(myUrl);
  if (searchParams.has("code")) {
    await fetch(url, {
      method: "POST",
      headers: {
        "Content-type": "application/json",
      },
      body: JSON.stringify({
        code: searchParams.get("code"),
      }),
    })
      .then(async (response) => {
        if (!response.ok) throw new Error("Respone is not ok");
        return response.json();
      })
      .then((data) => {
        console.log(data);

        localStorage.setItem(0, JSON.stringify(data));
        window.location.href = "/";
        return data;
      })
      .catch((error) => {
        alert(error);
      });
  }
}


async function registerUser() {
  let url = "http://localhost/api/auth/sign-up"

  let username = document.getElementById("register-nickname").value;
  let name = document.getElementById("register-name").value;
  let surname = document.getElementById("register-surname").value;
  let email = document.getElementById("register-email").value;
  let password = document.getElementById("register-password").value;

  let responseBody = {
    username,
    name,
    surname,
    email,
    password,
  }

  await fetch(url, {
    method: "POST",
    headers: {
      "Content-type": "application/json",
    },
    body: JSON.stringify(responseBody),
  })
    .then(async (response) => {
      if (!response.ok) throw new Error("Respone is not ok");
      return response.json();
    })
    .then((data) => {
      localStorage.setItem(0, JSON.stringify(data));
      window.location.href = "/";
      alert("registered")
      return data;
    })
    .catch((error) => {
      alert(error);
    });
}

async function signInUser() {
  let url = "http://localhost/api/auth/sign-in"

  let username = document.getElementById("sign-nickname").value;
  let password = document.getElementById("sign-password").value;

  let responseBody = {
    username,
    password,
  }

  await fetch(url, {
    method: "POST",
    headers: {
      "Content-type": "application/json",
    },
    body: JSON.stringify(responseBody),
  })
    .then(async (response) => {
      if (!response.ok) throw new Error("Respone is not ok");
      return response.json();
    })
    .then((data) => {
      localStorage.setItem(0, JSON.stringify(data));
      window.location.href = "/";
      return data;
    })
    .catch((error) => {
      alert(error);
    });
}

const formSignIn = document.getElementById("form-sign-in");

formSignIn.addEventListener("submit", (e) => {
  e.preventDefault();
  signInUser();
});
