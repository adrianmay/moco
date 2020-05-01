# moco
Motion detection. Docker-based opencv C(++) project

# Usage

make

docker build -t moco .
docker run -d --network host -v /out:/out moco

Hack the source to set the camera url or pass -d to the exe for the first inbuilt cam or -i for some file or url
The results get dropped on the /out volume


