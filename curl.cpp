// g++ curl.cpp -lcurl
#include <iostream>
#include <curl/curl.h>

int main() 
{
    CURL *handle;
    CURLcode res;
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_URL, "yahoo.co.jp");
    res = curl_easy_perform(handle);
    std::cout << "Hello, World!\n";
    return 0;
}
