Installer apache et php:
sudo apt-get install apache2
sudo apt install libapache2-mod-php

Démarrer et arrêter apache :
Démarrer : /etc/init.d/apache2 start
Arrêter : /etc/init.d/apache2 stop

Localisation du dossier par défaut :
/var/www/html/index.html

Créer un hôte virtuel :
Dans un terminal :
cd /var/www
sudo mkdir btssn1-22
sudo chmod 777 btssn1-22

-> Insérer un fichier index.html
cd /etc/apache2/sites-available
sudo cp 000-default.conf btssn1-22.conf

-> Dans le fichier :
ServerAdmin webmaster@btssn1-22.org
ServerName btssn1-22.org
ServerAlias www.btssn1-22.org
DocumentRoot /var/www/btssn1-22

sudo a2ensite btssn1-22.conf
sudo systemctl restart apache2

Aller dans le fichier hosts :
cd /etc

Dans le fichier "hosts" :
Ajouter la ligne :
127.0.0.1 btssn1-22.org

Désativer le localhost :
sudo a2dissite 000-default.conf
