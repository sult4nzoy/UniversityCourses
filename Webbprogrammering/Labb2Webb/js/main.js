/*
Författare: Omar Sultanzoy
Kurs: DT058G/DT100G, Webbprogrammering - Laboration 2
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Senast redigerad: 2026-01-22
*/

/*
 * Funktion: displayDataAndPlayMusic
 * Beskrivning: Renderar grundläggande information om den valda kanalen samt en ljudspelare.
 * Skapar även den container (#tableContainer) där tablån senare kommer att placeras.
 */
async function displayDataAndPlayMusic(channel, info) {
    const ID = channel.id;
    const name = channel.name;
    const tagline = channel.tagline;
    const audioUrl = channel.liveaudio.url;

    info.innerHTML = "";
    const songList = await getSongInformation(ID);
    const channelFormat = `
        <article>
        <h3>${name}</h3>
        <p><strong>${tagline}</strong></p>
        <hr>
        <audio controls autoplay src="${audioUrl}"></audio>
        
        <p><em>Föregående låt: ${songList[0]}</em></p>
        <p><em>Nästa låt: ${songList[1]}</em></p>

        <div id="tableContainer"></div>
        </article>
        `;

    info.innerHTML += channelFormat;
}
/*
 * Funktion: getSongInformation
 * Beskrivning: Försöker hämta information om låten, lyckas den så gör den det annars får vi "Ingen info hittades".
 */
async function getSongInformation(channelId) {

    const url = `https://api.sr.se/api/v2/playlists/rightnow?channelid=${channelId}&format=json`;
    try {
        const response = await fetch(url);
        const data = await response.json();
        const list = [];

        if (data.playlist) {
            if (data.playlist.previoussong) {
                const prevSong = data.playlist.previoussong.description;
                list.push(prevSong);
            }
            else {
                const prevSong = "Ingen info hittad";
                list.push(prevSong);
            }
            if (data.playlist.nextsong) {
                const nextSong = data.playlist.nextsong.description;
                list.push(nextSong);
            }
            else {
                const nextSong = "Ingen info hittad";
                list.push(nextSong);

            }
        }
        return list;
    }
    catch (error) {
        alert(error);
    }
}

/*
 * Funktion: programtablaInformationFetcher
 * Beskrivning: Hämtar tablå för en specifik kanal via SR API. 
 * Formaterar tider från råformat till klockslag och renderar listan i tableContainer.
 */
async function programtablaInformationFetcher(channelId) {
    const url = `https://api.sr.se/api/v2/scheduledepisodes?channelid=${channelId}&format=json&pagination=false`;
    const container = document.getElementById("tableContainer");

    try {
        const response = await fetch(url);
        const data = await response.json();
        const schedule = data.schedule;
        container.innerHTML = "";

        schedule.forEach(i => {
            const title = i.title;
            const description = i.description;


            const programHTML = `
            <article>
            <h3>${title}</h3>
            <p>${description}</p>
            </article>
            `;
            container.innerHTML += programHTML;
        });
    } catch (error) {
        alert(error);
    }
}
/*
 * Funktion: fetchData
 * Beskrivning: Hämtar samtliga kanaler och skapar navigeringslistan.
 * Sätter upp event listeners för kanalval och sökknappen för tablån.
 */
async function fetchData() {
    const url = "https://api.sr.se/api/v2/channels?format=json";
    let currentChannelId = 0;

    try {
        const response = await fetch(url);
        const data = await response.json();
        const channelsArray = data.channels;

        //console.log(channelsArray);

        const channelList = document.getElementById("mainnavlist");
        const info = document.getElementById("info");
        const searchBtn = document.getElementById("searchbutton");
        const searchProgram = document.getElementById("searchProgram");

        channelsArray.forEach(element => {
            const channelName = element.name;
            const channelImg = element.image;

            const li = document.createElement("li");
            const img = document.createElement("img");
            img.src = channelImg;
            img.width = 25;
            img.style.marginRight = "10px";

            li.appendChild(img);
            li.append(channelName);
            channelList.appendChild(li);

            const option = document.createElement("option");
            option.value = element.id;
            option.textContent = channelName;
            searchProgram.appendChild(option);

            li.addEventListener("click", () => {
                currentChannelId = element.id;
                searchProgram.value = element.id;
                try {
                    displayDataAndPlayMusic(element, info);
                }
                catch (error) {
                    alert(error);
                }
            });
        });

        searchProgram.addEventListener("change", () => {
            try {
                const selectedId = searchProgram.value;
                const selectedChannel = channelsArray.find(c => c.id == selectedId);
                currentChannelId = selectedChannel.id;
                displayDataAndPlayMusic(selectedChannel, info);
            }
            catch (error) {
                alert(error);
            }

        });

        searchBtn.addEventListener("click", () => {
            try {
                info.innerHTML = '<div id="tableContainer"></div>';
                programtablaInformationFetcher(currentChannelId);
            }
            catch (error) {
                alert(error);
            }

        });

    } catch (error) {
        alert(error);
    }

}

fetchData();