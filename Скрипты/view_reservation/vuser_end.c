vuser_end()
{
	lr_think_time(5);

	lr_start_transaction("transaction_logout");

	web_revert_auto_header("Sec-Fetch-User");
	
	web_reg_find("Text=A Session ID has been created",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("transaction_logout",LR_AUTO);
	
	lr_end_transaction("5_view_reservation_transaction", LR_AUTO);

	return 0;
}
