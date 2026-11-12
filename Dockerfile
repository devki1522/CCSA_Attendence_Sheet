FROM debian:bookworm-slim AS build

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    libasio-dev \
    libsqlite3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY CMakeLists.txt ./
COPY src ./src
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --parallel

FROM debian:bookworm-slim AS runtime

RUN apt-get update && apt-get install -y --no-install-recommends \
    libsqlite3-0 \
    && rm -rf /var/lib/apt/lists/* \
    && useradd --system --create-home --home-dir /app appuser

WORKDIR /app
COPY public ./public
COPY --from=build /app/build/CCSA_Attendence_Sheet ./CCSA_Attendence_Sheet
RUN mkdir -p /app/database && chown appuser:appuser /app/database

USER appuser
EXPOSE 27000
CMD ["./CCSA_Attendence_Sheet"]
