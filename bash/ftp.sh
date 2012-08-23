dir=`zenity --file-selection --directory`
password=`zenity  --title "Password" --entry --text "Enter password"`
#echo -e "$password\n" | sudo rm /var/www/ftp
echo -e "$password\n" | sudo -S ln -s "$dir" /var/www/
zenity --info --text "Linked The directory to apache2.Fetch ip/ftp on local system"
