VERSION 0.8
FROM alpine:3.19.1
RUN mkdir -p /app
WORKDIR /app
RUN apk update && apk upgrade && apk add libstdc++

all:
	BUILD +build
	BUILD +docker

build:
	RUN apk add build-base clang clang-dev alpine-sdk dpkg cmake ccache
	COPY ./src ./
	RUN g++ -o websvc main.cpp
	SAVE ARTIFACT websvc AS LOCAL build-output/websvc

docker:
	COPY +build/websvc ./
	ENTRYPOINT ["/app/websvc"]
	SAVE IMAGE websvc:latest
