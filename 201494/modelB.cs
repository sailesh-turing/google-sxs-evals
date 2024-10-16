// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

public class ModelB
{
    public static void Main(string[] args)
    {
        // Create a new glass with a capacity of 250ml
        GlassOfWater myGlass = new GlassOfWater(250);
        
        // Fill the glass
        myGlass.Fill(); 
        
        // Check if the glass is full
        if (myGlass.IsFull()) 
        {
            Console.WriteLine("The glass is full.");
        }
        
        // Drink some water (e.g., 50ml)
        myGlass._currentAmount -= 50;
        
        // Check the percentage full
        Console.WriteLine($"The glass is {myGlass.PercentageFull()}% full."); 
        
        // Empty the glass
        myGlass.Empty();
        
        // Check if the glass is empty
        if (myGlass.IsEmpty()) 
        {
            Console.WriteLine("The glass is empty.");
        }
        
        // Check the percentage full
        Console.WriteLine($"The glass is {myGlass.PercentageFull()}% full.");
    }
}

public class GlassOfWater
{
    private double _currentAmount;
    private readonly double _maxCapacity;

    public GlassOfWater(double maxCapacity)
    {
        _maxCapacity = maxCapacity;
        _currentAmount = 0;
    }

    public void Fill()
    {
        _currentAmount = _maxCapacity;
    }

    public void Empty()
    {
        _currentAmount = 0;
    }

    public double PercentageFull()
    {
        return (_currentAmount / _maxCapacity) * 100;
    }

    public bool IsFull()
    {
        return _currentAmount == _maxCapacity;
    }

    public bool IsEmpty()
    {
        return _currentAmount == 0;
    }
}