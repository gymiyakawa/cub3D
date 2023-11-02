rm -f log.txt
for file in ./maps/invalid/*
do
	echo "map passed: $file"
	echo $file >> log.txt
	leaks --atExit -- ./cub3d $file >> log.txt
done
cat log.txt | grep leaked