open Jest;
open Expect;
open DomReplace;

let htmlBegin = "<html><head></head><body>";
let htmlEnd = "</body></html>";

describe("DomReplace", () =>
  describe("textNode", () => {
    test("by tag name", () => {
      let oldText = "Foo";
      let text = "Bar";
      let selector = "h1";
      let html = htmlBegin ++ "<h1>" ++ oldText ++ "</h1>" ++ htmlEnd;
      let expectedHtml = htmlBegin ++ "<h1>" ++ text ++ "</h1>" ++ htmlEnd;
      let newHtml = textNode(~html, ~text, ~selector);
      expect(newHtml) |> toBe(expectedHtml);
    });

    test("by id", () => {
      let oldText = "Foo";
      let text = "Bar";
      let selector = "#my-title";
      let html = {j|$htmlBegin <h1>Something</h1><h2 id="my-title">$oldText</h2> $htmlEnd|j};
      let expectedHtml = {j|$htmlBegin <h1>Something</h1><h2 id="my-title">$text</h2> $htmlEnd|j};
      let newHtml = textNode(~html, ~text, ~selector);
      expect(newHtml) |> toBe(expectedHtml);
    });

    test("by className", () => {
      let oldText = "Foo";
      let text = "Bar";
      let selector = ".product-name";
      let html = {j|$htmlBegin <h1>Something</h1><h2 class="something product-name">$oldText</h2> $htmlEnd|j};
      let expectedHtml = {j|$htmlBegin <h1>Something</h1><h2 class="something product-name">$text</h2> $htmlEnd|j};
      let newHtml = textNode(~html, ~text, ~selector);
      expect(newHtml) |> toBe(expectedHtml);
    });

    test("invalid selector", () => {
      let oldText = "Foo";
      let text = "Bar";
      let selector = "h1.invalidClass";
      let html = {j|$htmlBegin<h1>$oldText</h1><h2>Subheading</h2><p>Paragraph</p>$htmlEnd|j};
      let newHtml = textNode(~html, ~selector, ~text);
      let expectedHtml = html;
      expect(newHtml) |> toBe(expectedHtml);
    });
  })
);
