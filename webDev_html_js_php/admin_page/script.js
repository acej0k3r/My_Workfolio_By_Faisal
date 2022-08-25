
	$('#checkAll').on('click',function(){
	$('input:checkbox').prop('checked', $(this).prop('checked'))
})
	
	document.getElementById("delete").onclick = function() {
		return confirm("Delete selected rows?");
	}	


	
			
	 let log_out = document.getElementById("logout");
    log_out.addEventListener("click", (event)=>{
        event.preventDefault();
        window.location.replace("login.html");
        
    })


