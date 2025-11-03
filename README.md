# unicorn

Overview-

This program defines a Unicorn class that ensures no two unicorns share the same name.
Each unicorn is magical and unique — when a unicorn is created, its name becomes “taken.”
When a unicorn is destroyed, its name becomes free again, allowing it to be reused.

This pattern demonstrates how to use static class variables to manage shared data across all instances of a class — a technique that’s useful for handling unique resources (like usernames, IDs, or system resources).

Features-

Prevents creation of two unicorns with the same name.

Throws an exception if a duplicate name is used.

Automatically frees up a name when a unicorn is destroyed.

Demonstrates RAII (Resource Acquisition Is Initialization) and static variable usage in C++.
