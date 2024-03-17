(function () {
    if (isLogin())
        isLogin();
})();

function isLogin() {
    const url = window.location.pathname;
    let loginStr = localStorage.getItem(0);
    var login;

    try {
        if (loginStr != undefined && !url.includes("/login")) {
            login = JSON.parse(loginStr);

            if (login.access_token == undefined) throw new Error("is not login");
        }
    } catch (error) {
        window.location.href = "login";
        return false;
    }
    return true;
}

