using System;
using System.IO;

class FileManager
{
    public string ReadFile(string ruta)
    {
        using (StreamReader reader = new StreamReader(ruta))
        {
            string content = reader.ReadToEnd();
            return content;
        }
    }

    public void WriteFile(string path, string content)
    {
        using (StreamWriter writer = new StreamWriter(path))
        {
            writer.Write(content);
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        FileManager fileManager = new FileManager();

        string filePath = "archivo.txt";

        Console.WriteLine($"El archivo se creará en: {Path.GetFullPath(filePath)}");

        fileManager.WriteFile(filePath, "Este es un texto de ejemplo.");

        string content = fileManager.ReadFile(filePath);

        if (content != null)
        {
            Console.WriteLine("Contenido del archivo:");
            Console.WriteLine(content);
        }
    }
}