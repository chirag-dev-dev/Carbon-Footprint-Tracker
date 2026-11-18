# Carbon Footprint Tracker — A C++ OOP Project on Sustainable Development

## About Me
- **Name:** Chirag
- **Student ID:** 02314803125
- **Branch:** Information Technology (IT)
- **Semester:** 3rd Semester, B.Tech
- **College:** Maharaja Agrasen Institute of Technology
- **Subject:** Object-Oriented Programming (OOPS)

## What This Project Is
For my OOPS subject, I built a small C++ program called the **Carbon Footprint
Tracker**. The idea behind it comes from sustainable development — the need to
measure and reduce the carbon emissions of everyday things around us.

The program calculates the carbon footprint (in kg of CO₂) for three different
types of entities: a **Building**, a **Car**, and a **Bicycle**. Each one uses
its own formula to work out its emissions, and the program prints a simple
report at the end.

I chose this topic because sustainability is one of the most relevant issues
today, and it gave me a natural way to apply OOP principles to a real-world
problem instead of writing a generic "student marks" program.

## The OOP Concepts I Applied

| Concept | How I used it in my code |
|---|---|
| **Abstraction** | I made `CarbonFootprint` an abstract base class with a pure virtual function `getCarbonFootprint()`. It defines *what* every entity must do, without saying *how*. |
| **Inheritance** | `Building`, `Car`, and `Bicycle` all inherit from `CarbonFootprint`, so they share a common interface. |
| **Polymorphism** | I store all objects in a `vector<CarbonFootprint*>` and loop over them. Each object runs its own version of `getCarbonFootprint()` even though the loop only sees base-class pointers. |
| **Encapsulation** | Data like `area`, `energyIntensity`, and `fuelConsumed` are kept `private` inside each class and only accessed through member functions. |
| **Virtual Destructor** | I added `virtual ~CarbonFootprint()` so that deleting objects through a base pointer correctly frees the derived objects too. |

## How to Run It

You'll need a C++ compiler (g++ works fine).

1. Clone the repo and move into the folder:
   ```bash
   git clone https://github.com/chirag-02314803125/Sustainable-Development-OOP.git
   cd Sustainable-Development-OOP
