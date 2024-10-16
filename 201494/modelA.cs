// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

public class ModelA
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
        
        // Drink some water (reduce the volume)
        myGlass._currentVolume -= 50;
        
        // Check the percentage full
        double percentage = myGlass.PercentageFull();
        Console.WriteLine($"The glass is {percentage}% full."); 
        
        // Empty the glass
        myGlass.Empty(); 
        
        // Check if the glass is empty
        if (myGlass.IsEmpty()) 
        {
            Console.WriteLine("The glass is empty.");
        }
        
        // Check the percentage full
        percentage = myGlass.PercentageFull();
        Console.WriteLine($"The glass is {percentage}% full.");
    }
}

public class GlassOfWater
{
    private double _currentVolume;
    private readonly double _maxVolume;

    public GlassOfWater(double maxVolume)
    {
        _maxVolume = maxVolume;
        _currentVolume = 0;
    }

    public void Fill()
    {
        _currentVolume = _maxVolume;
    }

    public void Empty()
    {
        _currentVolume = 0;
    }

    public double PercentageFull()
    {
        return (_currentVolume / _maxVolume) * 100;
    }

    public bool IsFull()
    {
        return _currentVolume == _maxVolume;
    }

    public bool IsEmpty()
    {
        return _currentVolume == 0;
    }
}