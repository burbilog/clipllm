# microsocks: tiny SOCKS5 server, built from source for reproducibility.
# It resolves the destination hostname server-side (SOCKS5 remote DNS),
# so it can reach the mock-llm service name inside the docker network.
FROM alpine:3.20 AS build
RUN apk add --no-cache build-base git
RUN git clone --depth 1 https://github.com/rofl0r/microsocks.git /src
WORKDIR /src
RUN make

FROM alpine:3.20
RUN apk add --no-cache libgcc
COPY --from=build /src/microsocks /usr/local/bin/microsocks
EXPOSE 1080
# -i bind ip, -p port. No -q so connection lines reach stderr / docker logs.
CMD ["microsocks", "-i", "0.0.0.0", "-p", "1080"]
