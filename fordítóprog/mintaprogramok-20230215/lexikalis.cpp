//Lexik�lis ford�t�
// K�sz�tette: M�szlai Zsanett 2021.02.12


//p�lda input: 12domosi12:={ize}12<>(**domosi**)$


#include <iostream>
#include <string.h> 
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "hu");

    string userinput= "";
    string output="";

    std::cout << "\nInput:\n~~~~~~~~~\n";

    getline(cin, userinput);
    int length =userinput.length();
    //cout << "Input length: "<<length;


   for (int i=0; i < length; ++i) {
      
       if (isdigit(userinput[i])) {
           while (isdigit(userinput[i])) {
               ++i;
           }
           output += "<el�jeln�lk�lieg�sz>";
       }
       if (isalpha(userinput[i])) {
           while (isalpha(userinput[i]) || isdigit(userinput[i])) {
               ++i;
           }
           output += "<v�ltoz�>";
       }
       if (userinput[i]==':' && userinput[i+1] == '=') {
           i=i+2;
           output += "<�rt�kad�s>";
       }
       
       //--------Ha { karaktert tal�l v�gigmegy a marad�k karakter sorozaton a } karakter els� el�fordul�s�t keresve
       if (userinput[i] == '{') {
           for (int j=i; j < length; ++j) {
               if (userinput[j] == '}') {
                   i = j;
                   output += "<{}komment>";
                   break;
               }
           }
       }

       //--------Ha ( �s * k�veti egym�st v�gigmegy a marad�k karakter sorozaton * ) karakterek els� el�fordul�s�t keresve
       if (userinput[i] == '(' && userinput[i+1]=='*') {
           for (int j = i+2; j < length; ++j) {
               if (userinput[j] == '*' && userinput[j+1]==')') {
                   i = j+1;
                   output += "<(**)komment>";
                   break;
               }
           }
        }
       
       if (userinput[i] == '<' && userinput[i + 1] == '>') {
           output += "<nemegyenl�>";

       }

       if (userinput[i] == '<' && userinput[i + 1] == '=') {
           output += "<kisebbegyenl�>";

       }

       if (userinput[i] == '>' && userinput[i + 1] == '=') {
           output += "<nagyobbegyenl�>";

       }

       //-----Amikor $ karaktert tal�l befejezi az elemz�st
       if (userinput[i] == '$') {
           output += "<EOF>";
           break; 
       }
   }

   cout <<"\nOutput:\n~~~~~~~~~\n"<< output << "\n \n \n";
}
