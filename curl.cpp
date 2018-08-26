// g++ curl.cpp -lcurl
#include <iostream>
#include <curl/curl.h>

static size_t curlWriteCallback(void *contents, size_t size, size_t nmemb, void *responseDataPtr) {
    ((std::string *)responseDataPtr)->append((char *)contents, size * nmemb);
        return size * nmemb;
        }

int main() 
{
    CURL *handle;
    CURLcode res;
    std::string responseData;
    handle = curl_easy_init();

    // url
    curl_easy_setopt(handle, CURLOPT_URL, "https://85742f9d-3f60-40a3-b456-487e0815417b.mock.pstmn.io/trial");
    // res func
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curlWriteCallback);
    // get res data
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &responseData);
    std::cout << "setting ready!\n";
    res = curl_easy_perform(handle);
    if (res != CURLE_OK) {
    	std::cerr << "curl error!\n";
    	return 1;
    } else {
        long response_code;
        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &response_code);
        if (response_code == 200) {
        std::cout << responseData << "\n";
        return 0;
        } else {
    	    std::cerr << "curl status not success: " << response_code << std::endl;
    	    return 1;
        }
    }
    std::cerr << "error!\n";
    return 1;
}
