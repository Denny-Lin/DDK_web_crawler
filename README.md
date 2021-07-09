# DDK_web_crawler
* It is a sample web crawler.
* Not finish yet.
* I am thinking about the structure and encapsulating the basic functions. Finally, I use python structure.
* 6/25, we can download anything, such as, pdf..., from the Internet.
* 7/3, we should use gethostbyname function (winsock.h) and create a function called DNStoIP();.
* 7/9, DNStoIP() is done;
* I will change connect() to be more flexible, such as, the user can input IP or address whatever he/she likes.
* It will be "connect(IP or address, port)".
* ...

* Analyze: <br>
![image](https://user-images.githubusercontent.com/67073582/124311936-172d6280-dba1-11eb-80b5-6d483d59e2c5.png) <br>
![image](https://user-images.githubusercontent.com/67073582/124312309-aa669800-dba1-11eb-80ab-558d560b2288.png) <br>

* Use queue to save all the subpages.
* Create a download function(type(ALL*, jpg, mp3, pdf, ...)).
* ...

# Platform
* Windows 10
* Visual studio 2017

# Language
* C/C++

# Features
* Fast
* Parallel

# What function will be added?
* Download pictures from website.
* Have a DNS function if necessary.
* Have a queue table of url.
* Use C++ std::thread library to send different url when connected.
* ...
