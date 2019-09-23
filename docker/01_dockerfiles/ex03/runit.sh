docker build -t gogs .
docker run -d -it --name gitgogs -p 3000:3000 gogs
