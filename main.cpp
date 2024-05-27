#include <iostream>
#include </Users/gridlink/Documents/json.hpp>
#include <curl/curl.h>

using json = nlohmann::json;

int main(int, char* argv[]) {


    std::string client="8649f784f1e34dd19c97a5c96381c278";
    std::string secret="13bd5805060b482aad45732d3e5cccba";
    std::string call="curl -X POST \"https://accounts.spotify.com/api/token\" \\\n"
                     "     -H \"Content-Type: application/x-www-form-urlencoded\" \\\n"
                     "     -d \"grant_type=client_credentials&client_id="+client+"&client_secret="+secret+"\"";
    FILE *in_stream = popen(call.c_str(), "r");
    json js = json::parse(in_stream);
    pclose(in_stream);
    std::string key = js["access_token"];
    std::cout << "Search for artist: ";
    std::string firstName, secondName;
    std::cin >> firstName;
    bool kat=false;
    if(std::cin.get()){
        kat=true;
    }
    system("clear");
    getline(std::cin, secondName);
    https://api.spotify.com/v1/search?q=remaster%2520artist%3AMiles%2520Davis&type=artist&market=US
    std::string givenUrl=R"('https://api.spotify.com/v1/search?q=remaster%2520artist%3A)"+firstName+R"(%2520)"+secondName+R"(&type=artist&market=US&limit=1')";
    //Should capture newline so I don't need to enter 'x'

    if(kat){
        givenUrl=R"('https://api.spotify.com/v1/search?q=remaster%2520artist%3A)"+firstName+R"(&type=artist&market=US&limit=1')";
    }
    std::string newUrl= givenUrl;
    std::string searchCall="curl --request GET \\\n --url "+newUrl+" \\\n --header 'Authorization: Bearer "+key+"'";

    FILE *in_stream2 = popen(searchCall.c_str(), "r");
    json searchResult = json::parse(in_stream2);
    pclose(in_stream2);

    json temp = searchResult.at("artists").at("items");

    json New=temp.at(0);;
    int c=0; std::string arId;
    for(auto u:New){
        if(c==4) {
            arId = u;
            break;
        }
        c++;
    }
    //Call for releases of artist
    std::string neCall=R"(curl --request GET \
  --url https://api.spotify.com/v1/artists/)"+arId+R"(/albums \
  --header 'Authorization: Bearer )"+key+R"(')";
    FILE *in_stream3 = popen(neCall.c_str(), "r");
    json neResult = json::parse(in_stream3);
    pclose(in_stream3);
    json New2 = neResult.at("items");
    std::cout << "What type of releases should I list? (compilation, single, album)" << std::endl;
    std::string typ;
    std::cin >> typ;
    system("clear");
    for(auto u:New2){
        int co=0;
        bool ok=false;
        for(auto w:u) {
            if(co==8&&ok){
                std::cout << w << std::endl;
            }else if(co==1&&w==typ){
                ok=true;
            }
            co++;
        }

    }

    return 0;
}
