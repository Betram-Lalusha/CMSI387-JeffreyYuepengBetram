/**
 * What command: takes user quey and returns search result from google search
 * api
 * @returns the response from google search api
 */
function what() {
  const commandLineArguments = process.argv.slice(2);

  if (commandLineArguments.length == 0) {
    console.log("please add search query");
    return;
  }

  let search = "";
  for (const element of commandLineArguments) {
    search += element + " ";
  }
  console.log("your search is ", search);
}

what();
