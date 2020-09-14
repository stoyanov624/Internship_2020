let mobile_account_btn = document.getElementById('acc_btn');
let mobile_social_btn = document.getElementById('soc_btn');
let mobile_bottom = document.getElementById('bot');
let mobile_log_console = document.getElementById('loging');

mobile_social_btn.addEventListener('click', () => {
    mobile_account_btn.style.backgroundColor ='#D1D6FF';
    mobile_social_btn.style.backgroundColor ='#FFFFFF';
    mobile_log_console.style.display = 'none';
    mobile_bottom.style.display = 'block';
});
    
mobile_account_btn.addEventListener('click', () => {
    mobile_bottom.style.display = 'none';
    mobile_log_console.style.display = 'block';
    mobile_social_btn.style.backgroundColor ='#D1D6FF';
    mobile_account_btn.style.backgroundColor ='#FFFFFF';
});

var media_screen = window.matchMedia("(min-width: 600px)");

media_screen.addEventListener("change", (e) => 
{
    if(e.matches) {
        mobile_log_console.style.display = 'block';
        mobile_bottom.style.display = 'block';
    }
    else
    {
        mobile_bottom.style.display = 'none';
    }
}
);
