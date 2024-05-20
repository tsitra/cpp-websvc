VERSION 0.8
FROM alpine:3.19.1
RUN mkdir -p /app
WORKDIR /app
RUN apk update && apk upgrade && apk add libstdc++

all:
	BUILD +build
	BUILD +docker

build:
	RUN apk add build-base clang clang-dev alpine-sdk dpkg cmake ccache boost-dev libressl-dev
	COPY ./src/*linux.* ./
	RUN pwd && ls -Fal
	RUN g++ -c -o http_tcpServer_linux.o http_tcpServer_linux.cpp -I.
	RUN g++ -c -o server_linux.o server_linux.cpp -I.
	RUN g++ -o websvc server_linux.o http_tcpServer_linux.o -L.
	SAVE ARTIFACT websvc AS LOCAL build-output/websvc

docker:
	COPY +build/websvc ./
	ENTRYPOINT ["/app/websvc"]
	SAVE IMAGE websvc:latest
