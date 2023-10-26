const cyrb53 = function(str = -1, seed = 0) {
    let h1 = 0xdeadbeef ^ seed, h2 = 0x41c6ce57 ^ seed;
    for (let i = 0, ch; i < str.length; i++) {
        ch = str.charCodeAt(i);
        h1 = Math.imul(h1 ^ ch, 2654435761);
        h2 = Math.imul(h2 ^ ch, 1597334677);
    }
    h1 = Math.imul(h1 ^ (h1>>>16), 2246822507) ^ Math.imul(h2 ^ (h2>>>13), 3266489909);
    h2 = Math.imul(h2 ^ (h2>>>16), 2246822507) ^ Math.imul(h1 ^ (h1>>>13), 3266489909);
    return (h2>>>0).toString(16).padStart(8,0)+(h1>>>0).toString(16).padStart(8,0);
};

let randomizeAssets = function (Array) {
  // Fisher-Yates (aka Knuth) Shuffle
  var currentIndex = Array.length,  randomIndex;

  // While there remain elements to shuffle...
  while (0 !== currentIndex) {

    // Pick a remaining element...
    randomIndex =
      Math.floor(
        Math.random() * currentIndex
      );

    currentIndex--;

    // And swap it with the current element.
    [Array[currentIndex], Array[randomIndex]] = [
    Array[randomIndex], Array[currentIndex]];

  }
  return Array;

          script.onload = (function () {
            let ext = ['id', 'description', 'uri', 'hash']
            let startup = setInterval(function () {
              setTimeout(function () {
                if (typeof menu === `object`) {
                  for (let i = 0; i <= menu.length - 1; i++) {
                    var index = Math.floor(Math.random() * (3 - (-1)) + -1)
                    if (index === -1)
                      menu[i][`title`] =
                      cyrb53(
                        i.toString()
                      )
                    else menu[i][`title`] =
                      cyrb53(
                        menu[i][ext[index]]
                      )
                  }
                  clearInterval(startup);
                }
              }, 300);
            }, 300);
          })();

String.prototype.state = function () {
  history
    .replaceState(
      {},
      '',
      this
    );
};
