#pragma once

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include <string>
#include <cstring>
#include <sstream>

namespace UserNameAfterligine
{
    std::string userName;
}

double GetCurrency(std::string& acronym);

std::string line(std::string userName, std::vector<std::string> vec)
{
    std::string doc = R"###({"user" : ")###" + userName + R"###(")###";
    for (int i = 0; i < vec.size(); i++)
    {
        doc += R"###(,"favorite)###" + std::to_string(i) + R"###(" : ")###" + vec[i] + R"###(")###";
    }
    doc += R"###(})###";
    return doc;
}

void UpdateMongoDoc(std::string& userName, std::vector<std::string>& vec)
{
    const auto uri = mongocxx::uri{ "mongodb+srv://mongo_user:LXkEj4dJLpY19PT0@cluster0.6yzdyrb.mongodb.net/" };

    mongocxx::client connection{ uri };

    auto collection = connection["new"]["tree"];

    std::string doc2 = R"###({"user" : ")###" + userName + R"###("})###";


    auto doc1 = bsoncxx::from_json(line(userName, vec));

    collection.insert_one(doc1.view());

    auto cursor = collection.find({});
    for (auto& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
    std::cout << "------------";
}

void FindMongoDoc(std::string userName)
{
    mongocxx::instance inst{};

    const auto uri = mongocxx::uri{ "mongodb+srv://mongo_user:LXkEj4dJLpY19PT0@cluster0.6yzdyrb.mongodb.net/" };

    mongocxx::client connection{ uri };

    auto collection = connection["new"]["tree"];

    //std::string line = "{\"user\" : \"" + userName + "\"}";

    auto cursor = collection.find(bsoncxx::from_json("{\"user\" : \"loreen\"}"));// ("{\"age\" : 18}")
    for (auto& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}

std::string favorites(int n, std::vector<std::string> favorites)
{
    std::string line;
    for (int i = 0; i < n; i++)
    {
        line += "<p style=\"color: #AD2A60;\"> " + favorites[i] + " : " + std::to_string(GetCurrency(favorites[i])) + " </p>\n";
    }
    return line;
}

std::vector<std::string> VectorFromLine(std::string& line)
{
    std::vector<std::string> vec;
    std::istringstream iss(line);
    std::string word;

    while (getline(iss, word, ' '))
    {
        vec.push_back(word);
    }
    return vec;
}

bool verification(std::string word)
{
    // that is works, but not free
    /*if (word.length() == 3)
    {
        return true;
    }
    else
    {
        return false;
    }*/
    return false;
}

void GetToupper(std::string& line)
{
    for (auto& elem : line)
    {
        elem = std::toupper(elem);
    }
}

std::string GetExchangeRates() {
    std::string apiKey = "fd8ace0b8d114a199d49bbde54ba2fe6";
    std::string response;

    // Формирование URL с API-ключом
    std::string url = "https://openexchangerates.org/api/latest.json?app_id=" + apiKey;

    // Отправка GET-запроса
    httplib::Client client("api.openexchangerates.org");
    auto res = client.Get(url.c_str());

    if (res && res->status == 200) {
        response = res->body;
    }
    else {
        std::cerr << "Ошибка при выполнении запроса: " << res.error() << std::endl;
    }

    return response;
}

double GetCurrency(std::string& acronym)
{
    double rysponse = 7.8;

    if (verification(acronym))
    {
        GetToupper(acronym);
        std::string response = GetExchangeRates();
        // Обработка ответа
        json root;

        // Парсинг JSON-ответа
        // response - строка с ответом от API
        std::stringstream ss(response);
        ss >> root;

        // Извлекаем значение валюты по ключу "USD" (доллар США)
        double usdRate = root["rates"][acronym];
        rysponse = usdRate;
        return rysponse;
    }
    else
    {
        std::cout << "error in verification data" << '\t'<<rysponse<<'\n';
        return rysponse;
    }
}


std::string TextSite()
{
    
    std::string site = R"###(<!DOCTYPE html>
<html>
<head>
    <title>logine</title>
    <style>
        .center {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 100vh;
            gap: 20px;
        }
    </style>
</head>
<body bgcolor="#BAC1C6">
    <div class="center">
        
              <form action="/logined" method="GET">
                  <p><h2 style="color: #AD2A60;">введите имя </h2></p>
                     <input style="color: #AD2A60;" type="text" name="param1">   
                    <br>
                    <form action="/example" method="GET">
                  <input style="color: #AD2A60;" type="submit" value="signin">
                </form>
            </div>         
        </form> 
    </div>
</body>
</html>
							)###";
    return site;
}

std::string TextSiteLogined(int n = 3, std::vector<std::string> vfavorites = { "rub", "usd", "eur" })
{
    std::string site = R"###(<!DOCTYPE html>
<html>
<head>
    <title>curency counter</title>
    <style>
        .center {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 100vh;
            gap: 20px;
        }
    </style>
</head>
<body bgcolor="#BAC1C6">
    <div class="center">
    <div style="display: flex; flex-direction: column;" justify-content: center; align-items: center;">
    <form action="/counted" method="GET">
        <p><h2 style="color: #AD2A60;">конвертировать валюту</h2></p>
        <br>
        валюта из: <input style="color: #AD2A60;" type="text" name="curencyfirst"> например "uah"
        <br>
        диапазон: <input style="color: #AD2A60;" type="text" name="curencyn"> например 78
        <br>
        валюта в: <input style="color: #AD2A60;" type="text" name="curencysecond"> например "rub"
        <br>
        <input style="color: #AD2A60;" type="submit" value="посчитать">
    </form>
    <br>
     <form>
        <p><h3 style="color: #AD2A60;">избранные валюты</h3></p>)###" +
        favorites(n, vfavorites) + R"###(
    </form>
        <form action="/example" method="GET">
            <input style="color: #AD2A60;" type="submit" value="изменить избранные">
        </form>
    </div>
</div>
</body>
</html>

							)###";
    return site;
}

std::string TextSiteCounted(std::string& curencyfirst, double& curencyN, std::string& curencysecond)
{
    std::string countedResult = u8"ошибка_в_валюте";

    if (GetCurrency(curencysecond) != 0 && GetCurrency(curencyfirst) != 0 && curencyN != 0)
    {
        countedResult = std::to_string((GetCurrency(curencysecond) / GetCurrency(curencyfirst)) * curencyN);
        std::cout << "connect name" << '\n';
    }
    std::cout << "disconnect name" << '\n';
    std::cout << std::to_string(GetCurrency(curencyfirst))<<'\n';
    std::cout << std::to_string(GetCurrency(curencysecond)) << '\n';
    std::string curencyfirstline = (GetCurrency(curencyfirst) != 0) ? (" : " + std::to_string(GetCurrency(curencyfirst))) : " : nothing_curency";
    std::string curencysecondline = (GetCurrency(curencysecond) != 0) ? (" : " + std::to_string(GetCurrency(curencysecond))) : " : nothing_curency";
    
    
    std::string button_again = u8"еще_раз";
    std::string site = u8R"###(<!DOCTYPE html>
<html>
<head>
    <title>result</title>
    <meta charset="utf-8">
    <style>
        .center {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 100vh;
            gap: 20px;
        }
    </style>
</head>
<body bgcolor="#BAC1C6">
    <div class="center">
     <h1 style="color: #AD2A60;">результат</h1>
     
    <form action="/logined" method="GET">
        <input type="text" style="color: #AD2A60;" name="999" value=)###" + countedResult + R"###(>
        <p style="color: #AD2A60;">)###" + curencyfirst + curencyfirstline + R"###(</p>
        <p style="color: #AD2A60;"> )###" + curencysecond + curencysecondline + R"###(</p>
        <input style="color: #AD2A60;" type="submit" value=)###" + button_again + u8R"###(>
    </form>
    <form action="/" method="GET">
        <input style="color: #AD2A60;" type="submit" value="logout">
    </form>
</div>
</div>
</body>
</html>

							)###";
    return site;
}

std::string TextSiteFavorite()
{

    std::string site = u8R"###(<!DOCTYPE html>
<html>
<head>
    <title>favirite curency</title>
    <meta charset="utf-8">
    <style>
        .center {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 100vh;
            gap: 20px;
        }
    </style>
</head>
<body bgcolor="#BAC1C6">
    <div class="center">
    <h2 style="color: #AD2A60;">ввод избранных валют</h2>
    <div style="display: flex; flex-direction: column; justify-content: center; align-items: center;">
     
    <iframe name="hiddenFrame" style="display:none;"></iframe>
        <form action="/example1" method="get" target="hiddenFrame">
        <input style="color: #AD2A60;" type="text" name="curencyfirst">
        <input style="color: #AD2A60;" type="submit" value="send">
    </form>
        
    <form action="/logined" method="GET">
        <input style="color: #AD2A60;"  type="submit" value="обратно">
    </form>
    <h3 style="color: #AD2A60;">например: rub usd...</h3>
    </div>
    
</div>
</body>
</html>


							)###";
    return site;
}


// функция для создания списка избранных с сайта и отправки в /logined