#include <iostream>
#include <vector>
#include <string>
#include <httplib.h>
#include <cookie.h>

using namespace httplib;

void setCookieHandler(const Request& req, Response& res) {
    // Создаём и заполняем новую структуру http.Cookie
    Cookie cookie;
    cookie.name = "exampleCookie";
    cookie.value = "Hello world!";
    cookie.path = "/";
    cookie.maxAge = 3600;
    cookie.httpOnly = true;
    cookie.secure = true;
    cookie.sameSite = Cookie::SameSiteLaxMode;

    // Используем метод Cookie::set_cookie() для отправки cookie клиенту.
    // За кулисами это добавляет заголовок `Set-Cookie` к ответу
    // содержащий необходимые данные cookie.
    Cookie::set_cookie(res, cookie);

    // Добавляем обычное тело запроса (на связано с cookie)
    res.set_content("cookie set!", "text/plain");
}

void getCookieHandler(const Request& req, Response& res) {
    // Получаем cookie из запроса по имени ("exampleCookie")
    // Если соответствующий cookie не найден, получим ошибку
    // cookie с пустым именем
    auto cookie = Cookie::get_cookie(req, "exampleCookie");

    if (cookie.name == "") {
        res.status = 403;
        return;
    }

    res.set_content(cookie.value, "text/plain");
}

int main() {
    Server svr;
    svr.Get("/set", setCookieHandler);
    svr.Get("/get", getCookieHandler);
    svr.listen("0.0.0.0", 8080);
}