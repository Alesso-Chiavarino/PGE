using System;

namespace CalculadoraInteractiva
{
    // Delegate for handling events
    public delegate void OperationPerformedEventHandler(double result);

    public class Calculator
    {
        // Events for each operation
        public event OperationPerformedEventHandler AdditionPerformed;
        public event OperationPerformedEventHandler SubtractionPerformed;
        public event OperationPerformedEventHandler MultiplicationPerformed;
        public event OperationPerformedEventHandler DivisionPerformed;

        // Method to add two numbers
        public void Add(double num1, double num2)
        {
            double result = num1 + num2;
            AdditionPerformed?.Invoke(result); // Invoke the event if not null
        }

        // Method to subtract two numbers
        public void Subtract(double num1, double num2)
        {
            double result = num1 - num2;
            SubtractionPerformed?.Invoke(result); // Invoke the event if not null
        }

        // Method to multiply two numbers
        public void Multiply(double num1, double num2)
        {
            double result = num1 * num2;
            MultiplicationPerformed?.Invoke(result); // Invoke the event if not null
        }

        // Method to divide two numbers
        public void Divide(double num1, double num2)
        {
            if (num2 == 0)
            {
                Console.WriteLine("Error: División por cero no permitida.");
                return;
            }
            double result = num1 / num2;
            DivisionPerformed?.Invoke(result); // Invoke the event if not null
        }
    }

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

    public sealed class Login
    {
        public string User { get; set; }
        public string Password { get; set; }


        private singleton() { }

        private static Singleton _instance;

        public static Singleton GetInstance()
        {
            if (_instance == null)
            {
                _instance = new Singleton();
            }
            return _instance;
        }

        public Login(string user, string password)
        {
            User = user;
            Password = password;
        }

        public bool ValidateUser()
        {
            if (User == "admin" && Password == "admin")
            {
                return true;
            }
            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Calculator calculator = new Calculator();

            // Subscribe the events to the handlers
            calculator.AdditionPerformed += ShowResult;
            calculator.SubtractionPerformed += ShowResult;
            calculator.MultiplicationPerformed += ShowResult;
            calculator.DivisionPerformed += ShowResult;

            // Interactive calculator loop
            while (true)
            {
                Console.WriteLine("\nCalculadora Interactiva:");
                Console.WriteLine("1. Sumar");
                Console.WriteLine("2. Restar");
                Console.WriteLine("3. Multiplicar");
                Console.WriteLine("4. Dividir");
                Console.WriteLine("5. Salir");
                Console.Write("Seleccione una opción: ");
                string option = Console.ReadLine();
                bool isLogged = false;

                if (option == "5")
                    break;

                try
                {
                    Console.Write("Ingrese el primer número: ");
                    double num1 = Convert.ToDouble(Console.ReadLine());

                    Console.Write("Ingrese el segundo número: ");
                    double num2 = Convert.ToDouble(Console.ReadLine());

                    Console.Write("Ingrese el usuario: ");
                    string user = Console.ReadLine();

                    Console.Write("Ingrese la contraseña: ");
                    string password = Console.ReadLine();

                    Login login = new Login(user, password);
                    isLogged = login.ValidateUser();

                    if (!isLogged) return;

                    switch (option)
                    {
                        case "1":
                            calculator.Add(num1, num2);
                            break;
                        case "2":
                            calculator.Subtract(num1, num2);
                            break;
                        case "3":
                            calculator.Multiply(num1, num2);
                            break;
                        case "4":
                            calculator.Divide(num1, num2);
                            break;
                        default:
                            Console.WriteLine("Opción no válida. Intente de nuevo.");
                            break;
                    }
                }
                catch (ArgumentOutOfRangeException)
                {
                    Console.WriteLine("Error: El archivo debe tener contenido");
                }
                catch (FormatException)
                {
                    Console.WriteLine("Error: Entrada no válida. Por favor, ingrese un número válido.");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Se produjo un error: {ex.Message}");
                }
            }
        }

        // Handler method to show the result of the operation
        static void WriteResultInFile(string path, double result)
        {
            FileManager fileManager = new FileManager();
            fileManager.WriteFile(path, "Resultado: " + result);
        }

        static void ShowResult(double result)
        {

            Console.WriteLine($"Resultado: {result}");
            Console.Write("¿Desea guardar el resultado en un archivo? (s/n): ");
            string option = Console.ReadLine();

            if (option == "s")
            {
                Console.Write("Ingrese la ruta del archivo: ");
                string path = Console.ReadLine();
                WriteResultInFile(path, result);
            }
        }
    }
}
