### Ejemplo 2: Simulación de un despachador de eventos con manejo avanzado

 **Elementos marcados** :

1. **Diseño de una clase que simula un bucle despachador de eventos** : `EventDispatcher` actúa como el despachador.
2. **Definición de eventos personalizados dentro de la clase** : `EventDispatched`.
3. **Manipulación de eventos mediante suscripciones y desencadenamientos** : `eventDispatcher.Subscribe("Evento1", Event1Handler);`.
4. **Simulación de la recepción y procesamiento de mensajes utilizando eventos** : `eventDispatcher.DispatchEvent("Evento1");`.

   using System;

   using System.Collections.Generic;

   using System.Threading;

namespace EventDispatcherSimulation

{

    // Definición de eventos personalizados dentro de la clase

    public delegate void EventHandler(object sender, EventArgs e);

    // Diseño de una clase que simula un bucle despachador de eventos

    public class EventDispatcher

    {

    private readonly Dictionary<string, EventHandler> eventHandlers = new Dictionary<string, EventHandler>();

    // Evento global

    public event EventHandler EventDispatched;

    // Suscripción a eventos

    public void Subscribe(string eventName, EventHandler eventHandler)

    {

    if (!eventHandlers.ContainsKey(eventName))

    {

    eventHandlers[eventName] = eventHandler;

    }

    else

    {

    eventHandlers[eventName] += eventHandler;

    }

    }

    // Desuscripción de eventos

    public void Unsubscribe(string eventName, EventHandler eventHandler)

    {

    if (eventHandlers.ContainsKey(eventName))

    {

    eventHandlers[eventName] -= eventHandler;

    }

    }

    // Simulación de la recepción y procesamiento de mensajes utilizando eventos

    public void DispatchEvent(string eventName)

    {

    Console.WriteLine($"Evento '{eventName}' despachado.");

    if (eventHandlers.ContainsKey(eventName))

    {

    eventHandlers[eventName]?.Invoke(this, EventArgs.Empty);

    }

    EventDispatched?.Invoke(this, EventArgs.Empty);

    Thread.Sleep(1000);  // Simulación de procesamiento

    }

    }

    class Program

    {

    static void Main()

    {

    EventDispatcher eventDispatcher = new EventDispatcher();

    // Manipulación de eventos mediante suscripciones y desencadenamientos

    eventDispatcher.Subscribe("Evento1", Event1Handler);

    eventDispatcher.Subscribe("Evento2", Event2Handler);

    eventDispatcher.EventDispatched += GlobalEventHandler;

    // Simulación de la recepción y procesamiento de mensajes utilizando eventos

    eventDispatcher.DispatchEvent("Evento1");

    eventDispatcher.DispatchEvent("Evento2");

    eventDispatcher.Unsubscribe("Evento1", Event1Handler);

    // Simulación de la recepción y procesamiento de mensajes utilizando eventos

    eventDispatcher.DispatchEvent("Evento1");

    eventDispatcher.DispatchEvent("Evento2");

    }

    static void Event1Handler(object sender, EventArgs e)

    {

    Console.WriteLine("Manejador del Evento1 ejecutado.");

    }

    static void Event2Handler(object sender, EventArgs e)

    {

    Console.WriteLine("Manejador del Evento2 ejecutado.");

    }

    static void GlobalEventHandler(object sender, EventArgs e)

    {

    Console.WriteLine("Manejador Global del Evento ejecutado.");

    }

    }

}
