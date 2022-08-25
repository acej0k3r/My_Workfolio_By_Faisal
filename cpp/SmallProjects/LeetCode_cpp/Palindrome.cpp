#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Palindrome
{
public:
    string longestPalindrome(string s)
    {
        string palinMid;
        string palindrome = "";
        string palinLargest;
        vector<string> palinVect;         
        bool isFirstRun = true;
        
        cout << "the string is " << s << endl;
        if (s.length() < 1 || s.length() > 1000)
        {
            cout << "Error String Must Be Between 1-1000" << endl;

            return "err";
        }
        
        // single letter palindrome
        if(s.length() == 1){                    
        
            cout << "The palindrome is : " << s << endl;

            return s;
        }    
            
    //if on first run check for all repeating char if so it is a palindrome 
    //else go through each case of the string and then compare all the palindromes to find largest
   
        
    string palinStart;   
    palinStart += s.at(0);
        
        for(int i=0; i <s.length()-1; i++){
            
            if(s[i] == s[i+1]){
                palinStart +=s.at(i+1);         
            }else{
    
            palinStart = "";
            isFirstRun = false;
            break; 
            }
        
        }
    
        
        if(isFirstRun == true){
            palinVect.push_back(palinStart);
        
        }
    
       
    
   if(!isFirstRun){
        
        for (int i = 1; i < s.length(); i++){
        
    
            //for 3 or more size palindrome
            // Loops through for loop and finds a mid point where the left side of the current i matches the right side of current i
            if (i != s.length()-1 && s.at(i - 1) == s.at(i + 1)){
                palinMid = "";
                // right < left ? then go right = 1, or go left = 0
                int totalMoveDirection = (((s.length()-i)-1) < i) ? 1 : 0;
                int totalMovableLength = 0;

                if (totalMoveDirection == 0)
                {
                    // if less spaces to left   
                    totalMovableLength += i+1;
                }
                else
                {
                    // less spaces to right
                    totalMovableLength += (s.length() - (i+2)) + 2;
                }
                
                //odd and center
                if(s.length() % 2 == 1 && i == (s.length()/2)){
                    
                    totalMovableLength = (s.length()/2) + 1; 
                
                }
    
    
                palinMid.assign({s.at(i - 1), s.at(i), s.at(i + 1)});   



                //k palindrome mid point
                
                

                string tempHolder;
                // check for further matching characters "<<<bb>>>" goes further out to match '<' '>', until totalMoveLength 
                for (int x = 2; x < totalMovableLength; x++)
                {
                    if ((i != 1) && (i != s.length() - 2))
                    {

                        if (s.at(i - x) == s.at(i + x))
                        {
                            tempHolder = s.at(i - x);
                            palinMid = tempHolder + palinMid;
                            palinMid += s.at(i + x);
                        }
                        else
                        {
                            
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
               
               
               //look for palindrome if "aaaa" where the repeating characters are s1 and s2
               
     
                if(palinMid.length() == 3){
                    for(int x = i; x < (s.length() - i - 1);x++){
                        if(s.at(i-1) == s.at(x+2) && s.at(i) == s.at(x+2)) //code end
                            palinMid += s.at(x+2);
                        else{
                            break;
                        }   
                    }
                }                 
                
               
                if(palinMid.length() > palinLargest.length()){
                    palinLargest = palinMid;
                    
                    palinVect.push_back(palinMid);
                
                }
               
                
               
               
              
            }
            
            
            //even palindrome goes by 2 characters ex: "aa in baab" as opposed to the odd if stmt ex: "b in tabat"
            if(i != s.length()-1 && s.at(i) == s.at(i+1)){
            
                palinMid = "";
               // right < left ? then go right = 1, or go left = 0
                int totalMoveDirection = (((s.length()-i)-1) < i) ? 1 : 0;
                int totalMovableLength = 0;

            if (totalMoveDirection == 0)
            {
                // if less spaces to left   
                totalMovableLength += i;
            }
            else
            {
                // less spaces to right
                totalMovableLength += (s.length() - i + 2);
            }
            
            //even and center
            if(s.length() % 2 == 1 && i == (s.length()/2) - 1){
                
                totalMovableLength = (s.length()/2) + 1; 
            
            } 
    

                palinMid.assign({s.at(i), s.at(i + 1)});   
                char *p1 = & s.at(i);
                char *p2 = & s.at(i+1);


                // palindrome mid point
                
                

                // check for further matching characters
                
                string tempHolder; 
                for (int x = 0; x < totalMovableLength; x++)
                {   
                
                    p1--; p2++;
                    
                    if(*p1 == *p2){
                        tempHolder = *p1;
                        palinMid = tempHolder + palinMid;
                        palinMid += *p2;
                    
                    
                    }else{
                        
                        break;
                    }
                
                }
               
               
    
                
                p1 = NULL;
                p2 = NULL;
              
               
               
                 
             if(palinMid.length() > palinLargest.length()){
                    palinLargest = palinMid;
                    
                    palinVect.push_back(palinMid);
                
                }
                
                
            }
            //#
                
            
                
                
        }//end of for
         //////////////
        
        
    }
        
        
        
        if(palinVect.size() > 1){
            cout << " [";
            for(int i=0; i<palinVect.size(); i++){
                cout << " " << palinVect[i] << ",";
            
            }
            
            cout << " ]";
            
            string palinFinal;
            for(int i=0;i<palinVect.size()-1;i++){
            palinFinal = (palinVect[i].size() >= palinVect[i+1].size()) ? palinVect[i] : palinVect[i+1];
            
                if(palindrome.size() <= palinFinal.size()){
                    palindrome = palinFinal;
            
                 }
            
            }
            

        }else if(palinVect.size() == 1){
        
            palindrome = palinVect[0];
        
        }else if(s.length() > 1 && palindrome == ""){
            if(s[0] == s[1]){
                palindrome = s[0];
                palindrome += s[1];
            }else{
                palindrome = s[0];

            }
        
        }
        
        
        

        if (palindrome != "")
        {
            cout << "The palindrome is : " << palindrome << endl;
            return palindrome;
        }
        else
        {
            cout << "No palindrome found" << endl;
            return "Invalid";
        }
    }
};