# Use the official Ubuntu base image
FROM ubuntu:20.04

# Set the working directory in the container
WORKDIR /usr/src/app

# Set environment variables
ENV TZ=Europe/London
ENV DEBIAN_FRONTEND=noninteractive
ENV XDG_RUNTIME_DIR=/tmp/runtime-root
ENV QT_DEBUG_PLUGINS=1

# Install required packages and configure timezone non-interactively
RUN apt-get update && \
    apt-get install -y software-properties-common wget build-essential libxcb-xinerama0 tzdata libgl1-mesa-dev libx11-xcb1 libxcb-render0 libxcb-shape0 libxcb-xfixes0 && \
    ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Add repository for Qt 5.15 and install Qt
RUN add-apt-repository ppa:beineri/opt-qt-5.15.2-focal && \
    apt-get update && \
    apt-get install -y qt515base qt515tools

# Create and set permissions for the XDG_RUNTIME_DIR
RUN mkdir -p /tmp/runtime-root && \
    chmod 700 /tmp/runtime-root

# Set the Qt environment
ENV PATH="/opt/qt515/bin:${PATH}"

# Copy the project files into the container
COPY . .

# Build the project
RUN qmake GuiApp.pro && \
    make

# Command to run the server application
CMD ["./GuiApp"]
