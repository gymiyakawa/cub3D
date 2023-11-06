rm -f log.txt
for file in ./maps/invalid/*
do
	echo $file >> log.txt
	leaks --atExit -- ./cub3D $file >> log.txt
	echo "map passed: $file"
done
	cat log.txt | grep -A 1 Error
	cat log.txt | grep leaked