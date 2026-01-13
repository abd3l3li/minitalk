# Minitalk

A small data exchange program using UNIX signals for inter-process communication.

## Description

**Minitalk** is a project that implements a client-server communication system using only UNIX signals (`SIGUSR1` and `SIGUSR2`). The client sends a string to the server by encoding each character into binary signals, and the server receives and decodes them back into text.

## How It Works

The communication is based on the following principles:
- The server displays its PID upon startup
- The client takes the server's PID and a string as parameters
- The client converts each character to binary and sends it bit by bit using signals
- `SIGUSR1` represents bit `0`
- `SIGUSR2` represents bit `1`
- The server receives signals, reconstructs the bits into characters, and displays them

## Features

- **Server**: Receives and displays strings from multiple clients sequentially
- **Client**: Sends strings to the server using only signals
- Fast and efficient bit-by-bit transmission
- Support for Unicode characters
- Error handling for invalid PIDs and communication failures

## Usage

```bash
# Compile
make

# Run server (in one terminal)
./server
# Server will display its PID: Server PID: 12345

# Run client (in another terminal)
./client [server_pid] "message to send"

# Example
./client 12345 "Hello, World!"
```

## Bonus Features

The bonus part includes:
- Server acknowledges every message received
- Support for Unicode characters (UTF-8)
- Client receives confirmation from server

```bash
# Compile bonus
make bonus

# Run bonus server
./server_bonus

# Run bonus client
./client_bonus [server_pid] "message"
```

## Technical Details

**Signals Used:**
- `SIGUSR1`: Represents binary `0`
- `SIGUSR2`: Represents binary `1`

**Signal Handling:**
- `sigaction()` for reliable signal handling
- Bitwise operations to encode/decode characters
- Proper timing to ensure signals aren't lost

## Project Structure

```
.
├── Makefile
├── client.c
├── server.c
├── minitalk.h
├── client_bonus.c
├── server_bonus.c
└── minitalk_bonus.h
```

## Testing

```bash
# Simple test
./client [PID] "Test message"

# Test with special characters
./client [PID] "Hello 42! 🚀"

# Test with long strings
./client [PID] "Lorem ipsum dolor sit amet, consectetur adipiscing elit..."

# Test with multiple clients
# Open multiple terminals and send messages simultaneously
```

## Key Concepts

- **UNIX Signals**: Understanding signal handling and inter-process communication
- **Binary Encoding**: Converting characters to binary representation
- **Bitwise Operations**: Manipulating individual bits
- **Process Communication**: Client-server architecture using PIDs
- **Signal Safety**: Handling asynchronous events properly

## Allowed Functions

- `write`
- `signal`
- `sigemptyset`
- `sigaddset`
- `sigaction`
- `kill`
- `getpid`
- `malloc`
- `free`
- `pause`
- `sleep`
- `usleep`
- `exit`

## Common Issues

- **Signal Loss**: Signals may be lost if sent too quickly; add small delays
- **Invalid PID**: Ensure the server PID is correct and the server is running
- **Permission Denied**: Check if you have permission to send signals to the process

## Performance

- Transmission speed depends on the delay between signals
- Average time for short messages: < 1 second
- Can handle strings of any length (limited only by system memory)

---

*A 42 School project - Learning the language of signals.*
