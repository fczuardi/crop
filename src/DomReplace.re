type loadedCheerio;
[@bs.module "cheerio"] external load : string => loadedCheerio = "";

let textNode = (~html, ~selector, ~text) => {
  let transform: (loadedCheerio, string, string) => string = [%bs.raw
    {|
  function(query, selector, text) {
    query(selector).text(text);
    return query.root().html();
  }
  |}
  ];
  transform(load(html), selector, text);
};
