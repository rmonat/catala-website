let frenchLaw = %raw(`require("../../assets/french_law.js")`)

let resetLog: unit => unit = %raw(`
  function() {
    return frenchLaw.eventsManager.resetLog(0);
  }
`)

let retrieveRawEventsSerialized: unit => array<LogEvent.Raw.eventSerialized> = %raw(`
  function() {
    return frenchLaw.eventsManager.retrieveRawEvents(0);
  }
`)

let retrieveEventsSerialized: unit => array<LogEvent.eventSerialized> = %raw(`
  function() {
    return frenchLaw.eventsManager.retrieveEvents(0);
  }
`)

let computeAllocationsFamiliales: Js.Json.t => float = %raw(`
  function(input) {
    frenchLaw.eventsManager.resetLog(0);
    return frenchLaw.computeAllocationsFamiliales(input);
  }
`)

let computeAidesAuLogement: Js.Json.t => float = %raw(`
  function(input) {
    frenchLaw.eventsManager.resetLog(0);
    return frenchLaw.computeAidesAuLogement(input);
  }
`)
