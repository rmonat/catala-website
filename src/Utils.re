let goToUrl = (url: string, _) => ReasonReactRouter.push("/" ++ url);

module TextLink = {
  [@react.component]
  let make = (~target: string, ~text: string) =>
    <a className=[%tw "text-primary visited:text-secondary"] href=target>
      {text |> React.string}
    </a>;
};

module CollapsibleCard = {
  [@react.component]
  let make = (~title: string, ~children) => {
    let (visible, setVisible) = React.useState(() => false);
    <div className=[%tw "bg-tertiary text-white my-4 p-4 shadow-lg"]>
      {if (visible) {
         <>
           <div className=[%tw "text-xl pb-2 font-bold"]>
             <a className=[%tw "cursor-pointer"] onClick={_ => setVisible(_ => false)}>
               <i className="float-left pr-1 text-white material-icons">
                 {"expand_less" |> React.string}
               </i>
               {"Collapse" |> React.string}
             </a>
           </div>
           <div> children </div>
         </>;
       } else {
         <div className=[%tw "text-xl pb-2 font-bold"]>
           <a className=[%tw "cursor-pointer"] onClick={_ => setVisible(_ => true)}>
             <i className="float-left pr-1 text-white material-icons">
               {"expand_more" |> React.string}
             </i>
             {title |> React.string}
           </a>
         </div>;
       }}
    </div>;
  };
};

module PageTitle = {
  [@react.component]
  let make = (~title: string) =>
    <h1 className=[%tw "text-3xl my-4"]>
      <span className=[%tw "border-solid border-b-2 border-tertiary text-tertiary"]>
        {title |> React.string}
      </span>
    </h1>;
};

module PageSection = {
  [@react.component]
  let make = (~title: string, ~children) => {
    <div>
      <h2 className=[%tw "text-2xl my-4"]>
        <span className=[%tw "border-solid border-b-2 border-secondary text-secondary"]>
          {title |> React.string}
        </span>
      </h2>
      children
    </div>;
  };
};

type presentation_card = {
  title: string,
  icon: option(string),
  quote: option(string),
  action: option((string, string)),
  content: React.element,
};

let render_presentation_card = (card: presentation_card) => {
  let action =
    switch (card.action) {
    | None => <div />
    | Some((url, action)) =>
      <div className=[%tw "border-solid border-t-2 border-primary pt-2"]>
        <a onClick={goToUrl(url)} className=[%tw "cursor-pointer uppercase text-primary"]>
          {action |> React.string}
        </a>
      </div>
    };
  let quote =
    switch (card.quote) {
    | Some(quote) =>
      <blockquote className=[%tw "text-primary pb-4"]>
        <strong> {quote |> React.string} </strong>
      </blockquote>
    | None => <div />
    };
  let icon =
    switch (card.icon) {
    | Some(icon) => <i className="float-left pr-2 material-icons"> {icon |> React.string} </i>
    | None => <span />
    };
  <div className=[%tw "w-full lg:w-1/2"]>
    <div className=[%tw "p-4 h-full"]>
      <div className=[%tw "bg-tertiary h-full overflow-hidden shadow-lg"]>
        <div className=[%tw "flex flex-col justify-between h-full px-6 py-4 text-white"]>
          <div>
            <div className=[%tw "text-xl pb-2 font-bold"]> icon {card.title |> React.string} </div>
            quote
            <p className=[%tw "pb-4"]> {card.content} </p>
          </div>
          action
        </div>
      </div>
    </div>
  </div>;
};

module Cards = {
  [@react.component]
  let make = (~cards: array(presentation_card)) => {
    <div className=[%tw "flex flex-row flex-wrap items-stretch"]>
      {cards->Belt.Array.map(card => render_presentation_card(card))->React.array}
    </div>;
  };
};
