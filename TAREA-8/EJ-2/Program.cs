using System;
using System.IO;

class FileManager
{
    public string ReadFile(string path)
    {
        try
        {
            using (StreamReader reader = new StreamReader(path))
            {
                string content = reader.ReadToEnd();
                return content;
            }
        }
        catch (FileNotFoundException ex)
        {
            Console.WriteLine($"Archivo no encontrado: {ex.Message}");
        }
        catch (UnauthorizedAccessException ex)
        {
            Console.WriteLine($"Acceso no autorizado: {ex.Message}");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Error de E/S: {ex.Message}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error desconocido: {ex.Message}");
        }

        return null;
    }
    
    public void WriteFile(string path, string content)
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(path))
            {
                writer.Write(content);
            }
        }
        catch (UnauthorizedAccessException ex)
        {
            Console.WriteLine($"Acceso no autorizado: {ex.Message}");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Error de E/S: {ex.Message}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error desconocido: {ex.Message}");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        try
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
        catch (UnauthorizedAccessException ex)
        {
            Console.WriteLine($"Error de acceso en el programa principal: {ex.Message}");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Error de E/S en el programa principal: {ex.Message}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error desconocido en el programa principal: {ex.Message}");
        }
    }
}