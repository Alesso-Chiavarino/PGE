using System;
using System.IO;

class FileManager
{
    public string ReadFile(string path)
    {
        try
        {

            if (path.GetType() != typeof(string))
            {
                throw new FormatException("El formato de la ruta es erroneo");
            }

            using (StreamReader reader = new StreamReader(path))
            {
                string content = reader.ReadToEnd();

                if (content.Length < 1)
                {
                    throw new ArgumentOutOfRangeException("El archivo debe tener contenido");
                }

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
        catch (ArgumentNullException ex)
        {
            Console.WriteLine($"al menos uno de los argumentos pasados es null: {ex.Message}");
        }
        catch (ArgumentOutOfRangeException ex)
        {
            Console.WriteLine($"el archivo no tiene contenido", ex.Message);
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

            fileManager.WriteFile(filePath, "");

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