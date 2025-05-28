Traffic Light Simulation with Interrupt in C++

This project simulates a simple traffic light system using multithreading in C++. It also includes an example of a basic interrupt mechanism using `std::atomic`.

 Project Purpose

The goal of this project is to:

- Learn how to create and manage threads in C++
- Use `std::atomic` for thread-safe flag control
- Simulate a traffic light that cycles through red, yellow, and green lights
- Implement an interrupt trigger that interacts with the running simulation

 What I Did

- Created a traffic light simulation that continuously displays red, yellow, and green states
- Used the `thread` library to run the simulation on a separate thread
- Added an `interrupt` flag using `std::atomic<bool>` to safely detect and respond to an external trigger
- Demonstrated how an interrupt can be caught and handled during the simulation

 What I Learned

- How to use `std::thread` to run functions in parallel
- How to control timing using `std::this_thread::sleep_for`
- The importance of thread-safe data access and how `std::atomic` helps avoid race conditions
- How to check and reset an interrupt flag within a running loop

![Ekran görüntüsü 2025-05-28 230036](https://github.com/user-attachments/assets/fd6ea3f8-f375-451f-a1bf-fe882d9c742d)
