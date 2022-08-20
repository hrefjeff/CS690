# Specs

ubuntu machine with t2.medium with 2 vCPUs and 8GB ram

# Initial commands

apt-apt-get dist-upgrade

## installing python

sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt install python3.9
python3.9 --version

# how to get in

-----BEGIN OPENSSH PRIVATE KEY-----
b3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAAAMwAAAAtz
c2gtZWQyNTUxOQAAACBOfSqAgveqWtz9zS7lpvLWHvS78NWZTnyAa9w3o7zdiQAA
AIj8DLF2/AyxdgAAAAtzc2gtZWQyNTUxOQAAACBOfSqAgveqWtz9zS7lpvLWHvS7
8NWZTnyAa9w3o7zdiQAAAEAwUQIBATAFBgMrZXAEIgQgVTHCq2An8PgnvJmOftG4
bU59KoCC96pa3P3NLuWm8tYe9Lvw1ZlOfIBr3DejvN2JAAAAAAECAwQF
-----END OPENSSH PRIVATE KEY-----

 ssh -i ~/.ssh/CS690.pem ubuntu@ec2-34-227-224-116.compute-1.amazonaws.com
