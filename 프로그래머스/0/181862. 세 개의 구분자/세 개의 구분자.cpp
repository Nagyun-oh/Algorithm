#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    for(int i=0;i<myStr.size();i++){
        if(myStr[i]=='a'||myStr[i]=='b'||myStr[i]=='c'){
            myStr[i]=' ';
        }
    }
   
    string temp = "";
    int len = myStr.size();
    for(int i=0;i<len;i++)
    {
        if(myStr[i]!=' ')
        {
            temp+=myStr[i];
        }
        else if(myStr[i]==' '&&temp!="") 
        {
            answer.push_back(temp);
            temp="";
        }
    }
   
    if(temp!="")answer.push_back(temp);
    else answer.push_back("EMPTY");
    
    return answer;
}