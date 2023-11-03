rm -f log.txt
for file in ./maps/*
do
	echo "map passed: $file"
	echo $file >> log.txt
	leaks --atExit -- ./cub3D $file >> log.txt
done
cat log.txt | grep leaked