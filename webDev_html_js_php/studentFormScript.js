
var title = document.title;
let usscInputs = document.getElementsByClassName("ussc");
let submission = document.getElementById("submitBtn");
let requiredInput = document.getElementsByClassName("reqInput");

let form = document.getElementById("studentForm");


if(title == "Student Form"){
    

    console.log("this is the student form USSC inputs will be disabled for student");
  
    
    for(let i = 0; i < usscInputs.length; i++){
        usscInputs[i].setAttribute("disabled","disabled");
        
    };
    
}



 



form.addEventListener("submit", (e)=>{
    
    
  
    for(let i=0; i < requiredInput.length; i++){
       
       e.preventDefault();
       
       if(requiredInput[i].value == ""){
           
           alert("One or more fields are empty. Please make sure you have inputted your date, cunyfirstId, last and first name, mailing address, office 365 email address, home tel, cell telephone, signature, and date.");
           return;
       }else{
           
           alert("Submission success");
           return;
       }
        
    }
    
}); 

                                                 
                                                   
submission.addEventListener("click", (e)=>{
    
});    
    
    


    let log_out = document.getElementById("logout");
    
    log_out.addEventListener("click", (event)=>{
        event.preventDefault();
        window.location.replace("login.html");
        
    });
                                                 

