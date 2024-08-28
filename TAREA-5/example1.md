### Ejemplo 1: Manejo básico de eventos con Publicador y Suscriptor

 **Elementos marcados** :

1. **Diseño de una clase que simula un bucle despachador de eventos** : No aplica directamente en este ejemplo.
2. **Definición de eventos personalizados dentro de la clase** : `EventoOcurrido`.
3. **Manipulación de eventos mediante suscripciones y desencadenamientos** : `publicador.EventoOcurrido += suscriptor.ManejadorEvento;`
4. **Simulación de la recepción y procesamiento de mensajes utilizando eventos** : `publicador.DispararEvento();`

   using System;

public class Publicador

{

    // Definición de eventos personalizados dentro de la clase

    public event EventHandler EventoOcurrido;

    // Método que dispara el evento

    public void DispararEvento()

    {

    // Simulación de la recepción y procesamiento de mensajes utilizando eventos

    EventoOcurrido?.Invoke(this, EventArgs.Empty);

    }

}

public class Suscriptor

{

    // Manejador de eventos que responde al evento

    public void ManejadorEvento(object sender, EventArgs e)

    {

    Console.WriteLine("El evento ha ocurrido.");

    }

}

class Program

{

    static void Main()

    {

    Publicador publicador = new Publicador();

    Suscriptor suscriptor = new Suscriptor();

    // Manipulación de eventos mediante suscripciones y desencadenamientos

    publicador.EventoOcurrido += suscriptor.ManejadorEvento;

    // Simulación de la recepción y procesamiento de mensajes utilizando eventos

    publicador.DispararEvento();

    }

}
