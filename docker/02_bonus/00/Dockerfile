FROM ubuntu

RUN apt-get update && apt-get upgrade -y && apt-get install -y git vim golang

RUN mkdir ~/go

WORKDIR /home/root/go/

RUN echo 'package main\n\nimport "fmt"\n\nfunc main() {	fmt.Printf("hello, world\\n")\n}' >> test.go

RUN go build test.go && ./test